SELECT mp.MEMBER_NAME, rr.REVIEW_TEXT, date_format(rr.REVIEW_DATE, "%Y-%m-%d") as REVIEW_DATE
FROM MEMBER_PROFILE as mp inner join REST_REVIEW as rr on mp.MEMBER_ID = rr.MEMBER_ID
WHERE rr.MEMBER_ID  in (
    select MEMBER_ID
    FROM REST_REVIEW
    group by MEMBER_ID having count(*) >= (select max(CNT)
                                      FROM (select MEMBER_ID, count(*) as CNT
                                                FROM REST_REVIEW
                                                group by MEMBER_ID) as A
                                      )
    )
 order by REVIEW_DATE asc, REVIEW_TEXT asc