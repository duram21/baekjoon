-- 코드를 입력하세요
SELECT RI.REST_ID, RI.REST_NAME, RI.FOOD_TYPE, FAVORITES as FAVORITES, RI.ADDRESS, ROUND(AVG(RR.REVIEW_SCORE), 2) as SCORE
FROM REST_INFO as RI inner join REST_REVIEW as RR on RI.REST_ID = RR.REST_ID
WHERE RI.ADDRESS like "서울%"
group by RR.REST_ID
order by SCORE desc, FAVORITES desc