-- 코드를 작성해주세요
select ITEM_ID, ITEM_NAME, RARITY
FROM ITEM_INFO
WHERE ITEM_ID not in (select PARENT_ITEM_ID
                 FROM ITEM_TREE
                    where PARENT_ITEM_ID is not null)
order by ITEM_ID DESC