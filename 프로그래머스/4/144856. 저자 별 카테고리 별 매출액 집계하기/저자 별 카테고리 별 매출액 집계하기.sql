with sale as (
    select BOOK_ID, sum(SALES) as SALES
    FROM BOOK_SALES
    where SALES_DATE like "2022-01%"
    group by BOOK_ID
)

select A.AUTHOR_ID, A.AUTHOR_NAME, B.CATEGORY, sum(B.PRICE * S.SALES) as TOTAL_SALES
FROM (BOOK as B join AUTHOR as A on B.AUTHOR_ID = A.AUTHOR_ID)  join sale as S on B.BOOK_ID = S.BOOK_ID
group by AUTHOR_ID, CATEGORY
order by AUTHOR_ID, CATEGORY DESC
