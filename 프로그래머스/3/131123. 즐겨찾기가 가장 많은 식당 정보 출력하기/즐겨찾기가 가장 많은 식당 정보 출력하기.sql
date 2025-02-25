-- 코드를 입력하세요
SELECT FOOD_TYPE, REST_ID, REST_NAME, FAVORITES
FROM REST_INFO
WHERE (FOOD_TYPE, FAVORITES) in 
        (SELECT FOOD_TYPE, max(FAVORITES) as FAV
        FROM REST_INFO
        GROUP BY FOOD_TYPE)
order by FOOD_TYPE DESC