-- 코드를 입력하세요
select cart_id
from
(    
SELECT CART_ID
FROM CART_PRODUCTS
WHERE NAME = 'Milk'
)
intersect
(
SELECT CART_ID
FROM CART_PRODUCTS
WHERE NAME = 'Yogurt'
)
order by cart_id asc;