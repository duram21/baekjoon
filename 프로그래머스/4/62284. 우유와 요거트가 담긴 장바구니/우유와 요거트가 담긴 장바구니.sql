-- 코드를 입력하세요
select CART_ID
FROM 
(SELECT *
FROM CART_PRODUCTS
group by CART_ID, NAME
having NAME = "Milk" or NAME = "Yogurt") as CP
group by CART_ID
having count(*) >= 2
order by CART_ID