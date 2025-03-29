CREATE OR REPLACE FUNCTION check_pre2015_games(
    f_input_date IN DATE
)
RETURN VARCHAR2
IS
    v_result VARCHAR2(100);
    v_count NUMBER := 0;
BEGIN
    -- First part of string
    v_result := 'Game ID''s of games launched before 2015: ';
    
    -- Collect game IDs released before 2015
    FOR game_rec IN (
        SELECT game_id
        FROM game_info
        -- Since it's a date, it can directly be compared without using TO_DATE()
        WHERE dor < f_input_date
        ORDER BY game_id
    ) LOOP
        -- Last part of string
        IF v_count > 0 THEN
            v_result := v_result || ', ';
        END IF;
        v_result := v_result || game_rec.game_id;
        v_count := v_count + 1;
    END LOOP;
    
    -- EXCEPTION: No games found
    IF v_count = 0 THEN
        v_result := 'No games were launched before 2015';
    END IF;
    
    RETURN v_result;
EXCEPTION
    WHEN OTHERS THEN
        RETURN 'Error checking games: ' || SQLERRM;
END check_pre2015_games;
/