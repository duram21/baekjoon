-- 코드를 입력하세요
SELECT month(START_DATE) as MONTH, CAR_ID, count(*) as RECORDS
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
WHERE year(START_DATE) = "2022" and (month(START_DATE) in("8", "9", "10"))
    and CAR_ID in(
        SELECT CAR_ID
        FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
        WHERE year(START_DATE) = "2022" and (month(START_DATE) in("8", "9", "10"))
        group by CAR_ID
        having count(*) >= 5)
group by CAR_ID, MONTH having RECORDS >= 1
ORDER BY MONTH, CAR_ID DESC