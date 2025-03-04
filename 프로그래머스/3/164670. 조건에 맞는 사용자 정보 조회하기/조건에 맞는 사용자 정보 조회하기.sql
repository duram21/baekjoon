-- 코드를 입력하세요
SELECT B.USER_ID, B.NICKNAME, concat(B.CITY, " ", B.STREET_ADDRESS1, " ", B.STREET_ADDRESS2) as '전체주소',
concat(substring(B.TLNO, 1, 3), "-", substring(B.TLNO, 4, 4), "-", substring(B.TLNO, 8,4)) as '전화번호'
FROM USED_GOODS_BOARD as A inner join USED_GOODS_USER as B on A.WRITER_ID = B.USER_ID
group by A.WRITER_ID
having count(*) >= 3
order by USER_ID DESC