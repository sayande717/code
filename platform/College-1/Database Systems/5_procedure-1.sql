SET SERVEROUTPUT ON;

CREATE OR REPLACE PROCEDURE insert_game(
    p_game_id IN NUMBER,
    p_game_name IN VARCHAR2,
    p_release_date IN DATE
)

IS
BEGIN
    -- Existing constraints from previous triggers will be auto-inherited 

    -- Insert the new game
    INSERT INTO game_info (game_id, game_name, dor)
    VALUES (p_game_id, p_game_name, NVL(p_release_date, SYSDATE));

    COMMIT;

    DBMS_OUTPUT.PUT_LINE('Game inserted successfully.');

-- Exception Handling:Duplicate data / other error (SQLERRM)
EXCEPTION
    WHEN DUP_VAL_ON_INDEX THEN
        ROLLBACK;
        RAISE_APPLICATION_ERROR(-20003, 'Game already exists');
    WHEN OTHERS THEN
        ROLLBACK;
        RAISE_APPLICATION_ERROR(-20004, 'An error occurred: ' || SQLERRM);
END insert_game;
/
