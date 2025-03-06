-- 코드를 작성해주세요
with recursive cte(ID, PARENT_ID, LEVEL) as (
    SELECT ID, PARENT_ID, 1
    FROM ECOLI_DATA
    WHERE PARENT_ID is null
    UNION ALL
    SELECT E.ID, E.PARENT_ID, cte.LEVEL + 1
    FROM cte join ECOLI_DATA as E on cte.ID= E.PARENT_ID
)

SELECT count(LEVEL) as COUNT, LEVEL as GENERATION
FROM cte
where ID not in (SELECT PARENT_ID
                FROM ECOLI_DATA
                WHERE PARENT_ID is not null)
group by LEVEL
order by GENERATION