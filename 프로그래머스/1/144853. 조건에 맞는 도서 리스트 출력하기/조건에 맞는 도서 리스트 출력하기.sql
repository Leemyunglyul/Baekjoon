-- 코드를 입력하세요
SELECT BOOK_ID, DATE_FORMAT(published_date, '%Y-%m-%d') published_date
FROM BOOK
WHERE YEAR(published_date)=2021 AND CATEGORY = '인문'
ORDER BY PUBLISHED_DATE ASC;