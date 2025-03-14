-- 코드를 입력하세요
SELECT date_format(SALES_DATE, "%Y-%m-%d") as SALES_DATE, PRODUCT_ID, USER_ID, SALES_AMOUNT
FROM
(SELECT SALES_DATE, PRODUCT_ID, USER_ID, SALES_AMOUNT
FROM ONLINE_SALE 
where SALES_DATE like "2022-03%"
union
SELECT SALES_DATE, PRODUCT_ID, NULL as USER_ID, SALES_AMOUNT
FROM OFFLINE_SALE
where SALES_DATE like "2022-03%") as A
order by SALES_DATE, PRODUCT_ID, USER_ID