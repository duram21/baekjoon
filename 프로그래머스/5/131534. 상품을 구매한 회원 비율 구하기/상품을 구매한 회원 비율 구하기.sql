with etc as (
    select 
        (select count(*)
        FROM USER_INFO
        WHERE YEAR(JOINED) = 2021
    ) as cnt
)

select YEAR(OS.SALES_DATE) as YEAR, MONTH(OS.SALES_DATE) as MONTH, count(DISTINCT UI.USER_ID) as PURCHASED_USERS, round(count(DISTINCT UI.USER_ID) / etc.cnt, 1) as PURCHASED_RATIO
FROM USER_INFO as UI join ONLINE_SALE as OS on UI.USER_ID = OS.USER_ID,etc
WHERE YEAR(UI.JOINED) = 2021
group by YEAR, MONTH
ORDER BY YEAR ASC, MONTH