-- 코드를 입력하세요
SELECT H.HISTORY_ID, round((datediff(H.END_DATE, H.START_DATE) + 1) * C.DAILY_FEE * ((100 - IFNULL(P.DISCOUNT_RATE,0)) / 100)) as FEE
FROM (CAR_RENTAL_COMPANY_CAR AS C join (SELECT CAR_ID, HISTORY_ID, START_DATE, END_DATE, 
                                                CASE
                                                    WHEN datediff(END_DATE, START_DATE) + 1 >= 90 THEN '90일 이상'
                                                    WHEN datediff(END_DATE, START_DATE) + 1 >= 30 THEN '30일 이상'
                                                    WHEN datediff(END_DATE, START_DATE) + 1 >= 7 THEN '7일 이상'
                                                    ELSE NULL
                                                END as DURATION_TYPE
                                        FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY)
                                        AS H on C.CAR_ID = H.CAR_ID)
                                        left join (SELECT DURATION_TYPE, DISCOUNT_RATE
                                                  FROM CAR_RENTAL_COMPANY_DISCOUNT_PLAN
                                                  WHERE CAR_TYPE = '트럭') as P on P.DURATION_TYPE = H.DURATION_TYPE
WHERE C.CAR_TYPE = '트럭'
order by  FEE DESC, HISTORY_ID DESC

