-- 코드를 입력하세요
SELECT LEFT(PRODUCT_CODE, 2) CATEGORY,
       COUNT(PRODUCT_ID) PRODUCTS
FROM PRODUCT
GROUP BY CATEGORY
ORDER BY CATEGORY ASC;