-- 코드를 입력하세요
SELECT FLAVOR 
FROM ICECREAM_INFO
WHERE FLAVOR in (SELECT FLAVOR
               FROM FIRST_HALF
               WHERE TOTAL_ORDER > 3000
               ORDER BY TOTAL_ORDER)   
    AND INGREDIENT_TYPE = "fruit_based"