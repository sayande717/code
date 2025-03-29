-- Before Insert Trigger
CREATE OR REPLACE TRIGGER before_insert_game_info
BEFORE INSERT ON game_info
FOR EACH ROW
BEGIN
    -- Log the attempt to insert a new game
    DBMS_OUTPUT.PUT_LINE('Attempting to insert new game: ' || :NEW.GAME_NAME);
    
    -- Set Constraint on `game_id`
    IF :NEW.GAME_ID <= 0 THEN
        RAISE_APPLICATION_ERROR(-20001, 'GAME_ID must be a positive number');
    END IF;
    
    -- Set Constraint on `game_name`
    IF :NEW.GAME_NAME IS NULL OR LENGTH(TRIM(:NEW.GAME_NAME)) = 0 THEN
        RAISE_APPLICATION_ERROR(-20002, 'GAME_NAME cannot be null or empty');
    END IF;
END;
/

-- After Insert Trigger
CREATE OR REPLACE TRIGGER after_insert_GAME_INFO
AFTER INSERT ON game_info
FOR EACH ROW
BEGIN
    -- Log the successful insertion of a new game
    DBMS_OUTPUT.PUT_LINE('Inserted. Game ID: ' || :NEW.GAME_ID || ', Name: ' || :NEW.GAME_NAME);
END;
/
