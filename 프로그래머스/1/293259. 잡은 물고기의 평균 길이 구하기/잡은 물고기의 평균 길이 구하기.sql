-- 코드를 작성해주세요
select round(avg(LENGTH), 2) as AVERAGE_LENGTH
FROM
    (select IFNULL(LENGTH, 10) as LENGTH
    FROM FISH_INFO) as A
