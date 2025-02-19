-- 코드를 작성해주세요
SELECT year(DIFFERENTIATION_DATE) as YEAR, (SELECT max(SIZE_OF_COLONY) 
                                   FROM ECOLI_DATA as A
                                   WHERE YEAR(A.DIFFERENTIATION_DATE) = YEAR(B.DIFFERENTIATION_DATE)
                                             ) - B.SIZE_OF_COLONY as YEAR_DEV, B.ID
FROM ECOLI_DATA as B
ORDER BY YEAR, YEAR_DEV