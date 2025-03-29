SET SERVEROUTPUT ON;

DECLARE
    -- Declare a cursor for the game_info table
    CURSOR c_game_info IS SELECT game_id,game_name FROM game_info;

    -- Variables
    v_game_id game_info.game_id%TYPE;
    v_game_name game_info.game_name%TYPE;
BEGIN
    -- Open and confirm that cursor is open
    OPEN c_game_info;
    -- Operation: var%ISOPEN
    IF c_game_info%ISOPEN THEN
        DBMS_OUTPUT.PUT_LINE('Cursor is open.');
    END IF;

    -- Fetch rows, one at a time
    LOOP
        FETCH c_game_info INTO v_game_id, v_game_name;

        -- Check attributes after each fetch
        -- Operation: var%FOUND
        IF c_game_info%FOUND THEN
            -- Operation: var%ROWCOUNT
            DBMS_OUTPUT.PUT_LINE('Row Count: ' || c_game_info%ROWCOUNT || '; Game ID: ' || v_game_id || ', Game Name: ' || v_game_name);
        -- Operation: var%NOTFOUND
        ELSIF c_game_info%NOTFOUND THEN
            DBMS_OUTPUT.PUT_LINE('No more rows to fetch.');
            EXIT; -- Exit the loop when no rows are left
        END IF;
    END LOOP;

    -- Close and confirm that the cursor is closed.
    CLOSE c_game_info;
    -- Operation: var%ISOPEN
    IF NOT c_game_info%ISOPEN THEN
        DBMS_OUTPUT.PUT_LINE('Cursor is closed.');
    END IF;
END;
/