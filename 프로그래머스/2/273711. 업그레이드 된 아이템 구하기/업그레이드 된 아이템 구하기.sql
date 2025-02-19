-- 코드를 작성해주세요
select ITEM_ID, ITEM_NAME, RARITY
FROM (ITEM_INFO)
WHERE ITEM_ID in (select B.ITEM_ID
FROM ITEM_INFO as A  inner join ITEM_TREE as B on A.ITEM_ID = B.PARENT_ITEM_ID
where A.RARITY = "RARE"
)
order by ITEM_ID DESC
