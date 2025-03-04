-- 코드를 입력하세요
SELECT A.APNT_NO, P.PT_NAME, P.PT_NO, A.MCDP_CD, D.DR_NAME, A.APNT_YMD
FROM (PATIENT as P inner join APPOINTMENT as A  on P.PT_NO = A.PT_NO) inner join DOCTOR as D
 on D.DR_ID = A.MDDR_ID
WHERE year(A.APNT_YMD) = 2022 and month(A.APNT_YMD) = 4 and day(A.APNT_YMD) = 13 and A.APNT_CNCL_YN = 'N' and A.MCDP_CD = 'CS'
order by APNT_YMD