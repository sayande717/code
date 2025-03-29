SET SERVEROUTPUT ON;

BEGIN
  DBMS_OUTPUT.PUT_LINE('Once we get in the loop, `c_game_info` will be implicitely created by SQL.');
  FOR c_game_info IN (SELECT * FROM game_info) LOOP
    DBMS_OUTPUT.PUT_LINE('Game ID: ' || c_game_info.game_id || ', Name: ' || c_game_info.game_name);
  END LOOP;
END;
/