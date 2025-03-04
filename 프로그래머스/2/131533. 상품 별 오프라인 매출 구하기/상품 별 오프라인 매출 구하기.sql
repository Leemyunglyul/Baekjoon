-- 코드를 입력하세요
SELECT a.PRODUCT_CODE, SUM(a.PRICE * b.SALES_AMOUNT) AS SALES
FROM PRODUCT a
INNER JOIN OFFLINE_SALE b
ON a.PRODUCT_ID = b.PRODUCT_ID
GROUP BY 1
ORDER BY 2 DESC,1;