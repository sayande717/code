-- Before Update Trigger
CREATE OR REPLACE TRIGGER before_update_game_info
BEFORE UPDATE ON game_info
FOR EACH ROW
BEGIN
    -- Log the attempt to update a game
    DBMS_OUTPUT.PUT_LINE('Attempting to update game: ' || :OLD.GAME_NAME);
    
    -- Set Constraint on `game_id`
    IF :NEW.GAME_ID != :OLD.GAME_ID THEN
        RAISE_APPLICATION_ERROR(-20003, 'GAME_ID cannot be updated');
    END IF;
    
    -- Set Constraint on `game_name`
    IF :NEW.GAME_NAME IS NULL OR LENGTH(TRIM(:NEW.GAME_NAME)) = 0 THEN
        RAISE_APPLICATION_ERROR(-20004, 'GAME_NAME cannot be updated to null or empty');
    END IF;
END;
/

-- After Update Trigger
CREATE OR REPLACE TRIGGER after_update_game_info
AFTER UPDATE ON game_info
FOR EACH ROW
BEGIN
    -- Log the successful update of the game
    DBMS_OUTPUT.PUT_LINE('Updated. Game ID: ' || :NEW.GAME_ID || ', Name: ' || :NEW.GAME_NAME);
END;
/