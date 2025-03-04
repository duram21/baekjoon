-- 코드를 입력하세요
SELECT CRCC.CAR_ID, CRCC.CAR_TYPE, ROUND(CRCC.DAILY_FEE *  30 * (100 - CRCDP.DISCOUNT_RATE) / 100, 0) as FEE
FROM CAR_RENTAL_COMPANY_CAR as CRCC inner join CAR_RENTAL_COMPANY_DISCOUNT_PLAN as CRCDP 
        on CRCC.CAR_TYPE = CRCDP.CAR_TYPE
WHERE CRCC.CAR_ID not in
                    (select CAR_ID
                    FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
                    WHERE START_DATE <= '2022-11-30' and END_DATE >= '2022-11-01')
        and CRCC.CAR_TYPE in ('세단', 'SUV')
        and CRCDP.DURATION_TYPE = "30일 이상"
having FEE >= 500000 and FEE < 2000000
order by FEE DESC, CAR_TYPE ASC, CAR_ID DESC        

     
                         
                         