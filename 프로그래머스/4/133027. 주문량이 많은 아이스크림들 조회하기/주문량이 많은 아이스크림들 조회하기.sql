-- 코드를 입력하세요
select FLAVOR
FROM(
select FLAVOR, sum(TOTAL_ORDER) as TOTAL_ORDER
FROM (select * FROM FIRST_HALF union all select * FROM JULY) as C
group by FLAVOR
order by TOTAL_ORDER desc
limit 3) as CC