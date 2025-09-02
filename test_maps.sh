#!/bin/bash

# Colores para la salida
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

echo -e "${BLUE}=== TESTING SO_LONG MAPS ===${NC}\n"

# Compilar el proyecto
echo -e "${YELLOW}Compiling project...${NC}"
make re > /dev/null 2>&1

if [ $? -ne 0 ]; then
    echo -e "${RED}Compilation failed${NC}"
    exit 1
fi

echo -e "${GREEN}✓ Compilation successful${NC}\n"

# Función para probar un mapa
test_map() {
    local map_file=$1
    local expected_result=$2  # "valid" o "invalid"
    local description=$3

    echo -e "${BLUE}Testing: ${map_file}${NC}"
    echo -e "Description: ${description}"
    
    # Ejecutar so_long con timeout de 3 segundos
    timeout 3s ./so_long "${map_file}" > /dev/null 2>&1
    local exit_code=$?
    
    if [ "$expected_result" = "invalid" ]; then
        if [ $exit_code -eq 1 ]; then
            echo -e "${GREEN}✓ PASS: Map rejected as expected${NC}"
        else
            echo -e "${RED}✗ FAIL: Map should have been rejected (exit code: $exit_code)${NC}"
        fi
    else  # expected_result = "valid"
        if [ $exit_code -eq 124 ]; then  # Timeout = se ejecutó correctamente
            echo -e "${GREEN}✓ PASS: Map loaded successfully${NC}"
        elif [ $exit_code -eq 0 ]; then  # Terminó normalmente (también válido)
            echo -e "${GREEN}✓ PASS: Map completed successfully${NC}"
        else
            echo -e "${RED}✗ FAIL: Valid map was rejected (exit code: $exit_code)${NC}"
        fi
    fi
    echo ""
}

echo -e "${YELLOW}=== INVALID MAPS ===${NC}\n"

test_map "maps/no_player.ber" "invalid" "Map without player"
test_map "maps/no_exit.ber" "invalid" "Map without exit"
test_map "maps/no_collectibles.ber" "invalid" "Map without collectibles"
test_map "maps/multiple_players.ber" "invalid" "Map with multiple players"
test_map "maps/open_wall.ber" "invalid" "Map with open wall"
test_map "maps/invalid_chars.ber" "invalid" "Map with invalid characters"
test_map "maps/unreachable_collectible.ber" "invalid" "Unreachable collectible"
test_map "maps/unreachable_exit.ber" "invalid" "Unreachable exit"
test_map "maps/empty.ber" "invalid" "Empty map"
test_map "maps/too_small.ber" "invalid" "Map too small"
test_map "maps/not-rectangular.ber" "invalid" "Non-rectangular map"
test_map "maps/multiple_exits.ber" "invalid" "Map with multiple exits"

echo -e "${YELLOW}=== VALID MAPS ===${NC}\n"

test_map "maps/example.ber" "valid" "Basic example map"
test_map "maps/minimal_valid.ber" "valid" "Minimal valid map"
test_map "maps/many_collectibles.ber" "valid" "Map with many collectibles"
test_map "maps/long_narrow.ber" "valid" "Long narrow map"
test_map "maps/tall_narrow.ber" "valid" "Tall narrow map"
test_map "maps/maze.ber" "valid" "Maze map"
test_map "maps/large_open.ber" "valid" "Large open map"
test_map "maps/snake_path.ber" "valid" "Snake path map"
test_map "maps/big_map.ber" "valid" "Big map"

echo -e "${YELLOW}=== ENEMY MAPS (BONUS) ===${NC}\n"

test_map "maps/one_enemy.ber" "valid" "Simple map with one enemy"
test_map "maps/with_enemies.ber" "valid" "Basic map with enemies"
test_map "maps/enemy_maze.ber" "valid" "Maze with enemies"
test_map "maps/enemy_challenge.ber" "valid" "Challenge with enemies"
test_map "maps/enemy_blocked.ber" "valid" "Map with enemies"

echo -e "${BLUE}=== TESTING COMPLETED ===${NC}"
