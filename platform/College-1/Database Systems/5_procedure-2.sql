CREATE OR REPLACE PROCEDURE update_linux_compatibility(
    p_game_id IN NUMBER,
    p_compatible IN VARCHAR2
)
IS
    v_compat_flag NUMBER;
    v_game_count NUMBER;
BEGIN
    -- Validate input parameters
    IF p_game_id IS NULL OR p_game_id <= 0 THEN
        RAISE_APPLICATION_ERROR(-20030, 'Invalid Game ID');
    END IF;
    
    -- Convert string input to numeric flag
    CASE UPPER(p_compatible)
        WHEN 'YES' THEN v_compat_flag := 1;
        WHEN 'NO' THEN v_compat_flag := 0;
        ELSE RAISE_APPLICATION_ERROR(-20031, 'Invalid compatibility value. Use ''YES'' or ''NO''');
    END CASE;
    
    -- Verify game existence on base table `GAME_INFO`
    SELECT COUNT(*) INTO v_game_count
    FROM game_info
    WHERE game_id = p_game_id;
    
    IF v_game_count = 0 THEN
        RAISE_APPLICATION_ERROR(-20032, 'Game ID ' || p_game_id || ' not found');
    END IF;
    
    -- Insert compatibility record
    INSERT INTO linux_compat (game_id, compatible)
    VALUES (p_game_id, v_compat_flag);
    
    COMMIT;
    
    DBMS_OUTPUT.PUT_LINE('Inserted Compatibility for Game ID: ' || p_game_id);

-- Handle exceptions: Record already exists.
EXCEPTION
    WHEN DUP_VAL_ON_INDEX THEN
        ROLLBACK;
        RAISE_APPLICATION_ERROR(-20033, 'A compatibility record already exists for Game ID: ' || p_game_id);
    WHEN OTHERS THEN
        ROLLBACK;
        RAISE;
END update_linux_compatibility;
/