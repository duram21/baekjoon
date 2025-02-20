-- 코드를 입력하세요
SELECT MCDP_CD as 진료과코드 ,count(*) as 5월예약건수
FROM APPOINTMENT
WHERE year(APNT_YMD) = 2022 and month(APNT_YMD) = 5
GROUP BY MCDP_CD
order by 5월예약건수, 진료과코드