SELECT COUNT(a.ID) FISH_COUNT, b.FISH_NAME
FROM FISH_INFO a
INNER JOIN FISH_NAME_INFO b
ON a.FISH_TYPE = b.FISH_TYPE
GROUP BY 2
ORDER BY 1 DESC;