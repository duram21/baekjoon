-- 코드를 입력하세요
SELECT YEAR(SALES_DATE) as YEAR, MONTH(SALES_DATE) as MONTH, count(DISTINCT UI.USER_ID) as PURCHASED_USERS,
round(count(DISTINCT UI.USER_ID) / (SELECT COUNT(USER_ID)
                             FROM USER_INFO
                             WHERE JOINED like "2021%"),1 ) as PUCHASED_RATIO
 
FROM USER_INFO as UI join ONLINE_SALE as OS on UI.USER_ID = OS.USER_ID
WHERE UI.JOINED like "2021%"
GROUP BY YEAR, MONTH
order by year, month