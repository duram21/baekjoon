-- 코드를 작성해주세요
select A.DEPT_ID, A.DEPT_NAME_EN, round(avg(B.SAL)) as AVG_SAL
from HR_DEPARTMENT as A inner join HR_EMPLOYEES as B on A.DEPT_ID = B.DEPT_ID
group by DEPT_ID
ORDER BY AVG_SAL DESC