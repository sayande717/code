-- Before Delete Trigger
CREATE OR REPLACE TRIGGER before_delete_game_info
BEFORE DELETE ON game_info
FOR EACH ROW
BEGIN
    -- Delete platform compatibility records first
    DELETE FROM linux_compat WHERE game_id = :OLD.GAME_ID;
    DELETE FROM mac_compat WHERE game_id = :OLD.GAME_ID;
    DELETE FROM win_compat WHERE game_id = :OLD.GAME_ID;
    
    DBMS_OUTPUT.PUT_LINE('Cleaned up all records for Game ID: ' || :OLD.GAME_ID);
END;
/

-- After Delete Trigger
CREATE OR REPLACE TRIGGER after_delete_game_info
AFTER DELETE ON game_info
FOR EACH ROW
BEGIN
    -- Log the successful deletion of the game
    DBMS_OUTPUT.PUT_LINE('Deleted Game with ID: ' || :OLD.GAME_ID);
END;
/