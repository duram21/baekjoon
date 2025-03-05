-- 코드를 작성해주세요
SELECT HE.EMP_NO, HE.EMP_NAME, HG.GRADE, CASE
                                        WHEN HG.GRADE = 'S' THEN SAL * 0.2
                                        WHEN HG.GRADE = 'A' THEN SAL * 0.15
                                        WHEN HG.GRADE = 'B' THEN SAL * 0.1
                                        ELSE 0
                                        END AS BONUS
FROM HR_EMPLOYEES as HE join (SELECT  EMP_NO, 
                                CASE
                                  WHEN AVG(SCORE) >= 96 THEN 'S'
                                  WHEN AVG(SCORE) >= 90 THEN 'A'
                                  WHEN AVG(SCORE) >= 80 THEN 'B'
                                  ELSE 'C'
                                 END as GRADE
                             FROM HR_GRADE
                              group by EMP_NO
                             ) as HG on HE.EMP_NO = HG.EMP_NO

ORDER BY EMP_NO
