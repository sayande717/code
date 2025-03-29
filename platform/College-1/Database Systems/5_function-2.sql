CREATE OR REPLACE FUNCTION check_mac_compatibility(p_game_id IN NUMBER)
RETURN VARCHAR2
IS
    v_compatible NUMBER;  -- Changed variable name for clarity
    v_game_name VARCHAR2(100);
BEGIN
    -- Check if the game exists in game_info table
    BEGIN
        SELECT game_name INTO v_game_name
        FROM game_info
        WHERE game_id = p_game_id;
    EXCEPTION
        WHEN NO_DATA_FOUND THEN
            RETURN 'Game with ID ' || p_game_id || ' doesn''t exist in the base table.';  -- Fixed quote
    END;

    -- Check compatibility (using correct column name)
    BEGIN
        SELECT compatible INTO v_compatible  -- Changed to 'compatible'
        FROM mac_compat
        WHERE game_id = p_game_id;

        IF v_compatible = 1 THEN
            RETURN v_game_name || ' is compatible with macOS.';
        ELSE
            RETURN v_game_name || ' is not compatible with macOS.';
        END IF;
    EXCEPTION
        WHEN NO_DATA_FOUND THEN
            RETURN 'Game with ID ' || p_game_id || ' doesn''t exist in the macOS compatibility table.';  -- Fixed quote
    END;

EXCEPTION
    WHEN OTHERS THEN
        RETURN 'Error checking macOS compatibility: ' || SQLERRM;
END check_mac_compatibility;
/