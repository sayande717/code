DECLARE
    -- Variables for storing counts
    rows_all NUMBER := 0;
    rows_linux NUMBER := 0;
    rows_mac NUMBER := 0;
    rows_win NUMBER := 0;
BEGIN
    -- Total rows in base table
        FOR row IN (SELECT * FROM game_info) LOOP
            rows_all := rows_all + 1;
        END LOOP;

        -- Total rows in Linux table, for compatible games
        FOR row IN (SELECT * FROM linux_compat WHERE compatible = 1) LOOP
            rows_linux := rows_linux + 1;
        END LOOP;

        -- Total rows in Mac table, for compatible games
        FOR row IN (SELECT * FROM mac_compat WHERE compatible = 1) LOOP
            rows_mac := rows_mac + 1;
        END LOOP;

        -- Total rows in Windows table, for compatible games
        FOR row IN (SELECT * from win_compat WHERE compatible = 1) LOOP
            rows_win := rows_win + 1;
        END LOOP;

        -- Display results
        DBMS_OUTPUT.PUT_LINE('Total Rows: ' || rows_all);
        
        DBMS_OUTPUT.PUT_LINE('Table: Linux');
        DBMS_OUTPUT.PUT_LINE('Compatible: ' || rows_linux || ', Incompatible: ' || (rows_all - rows_linux));
        
        DBMS_OUTPUT.PUT_LINE('Table: Mac');
        DBMS_OUTPUT.PUT_LINE('Compatible: ' || rows_mac || ', Incompatible: ' || (rows_all - rows_mac));
        
        DBMS_OUTPUT.PUT_LINE('Table: Windows');
        DBMS_OUTPUT.PUT_LINE('Compatible: ' || rows_win || ', Incompatible: ' || (rows_all - rows_win));
END;
-- IMPORTANT: Give this escape character at last to signify the end of the program.
/