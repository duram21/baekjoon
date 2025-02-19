-- 코드를 작성해주세요
SELECT A.FISH_COUNT, FISH_NAME_INFO.FISH_NAME

FROM (SELECT FISH_TYPE, COUNT(*) as FISH_COUNT
                                FROM FISH_INFO
                                GROUP BY FISH_TYPE) as A 
    left join FISH_NAME_INFO on FISH_NAME_INFO.FISH_TYPE = A.FISH_TYPE
                                
ORDER BY FISH_COUNT DESC