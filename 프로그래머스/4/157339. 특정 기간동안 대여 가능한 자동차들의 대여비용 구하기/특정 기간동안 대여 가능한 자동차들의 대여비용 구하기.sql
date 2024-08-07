SELECT A.CAR_ID, A.CAR_TYPE, FLOOR(A.DAILY_FEE*(1-(B.DISCOUNT_RATE*0.01))*30) AS FEE
FROM CAR_RENTAL_COMPANY_CAR A LEFT JOIN (
    SELECT CAR_TYPE, DISCOUNT_RATE
    FROM CAR_RENTAL_COMPANY_DISCOUNT_PLAN
    WHERE DURATION_TYPE = '30일 이상'
) B ON A.CAR_TYPE = B.CAR_TYPE
WHERE 
A.CAR_TYPE IN ('SUV', '세단') AND
A.CAR_ID NOT IN(
SELECT CAR_ID
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
WHERE END_DATE >= TO_DATE('2022-11-01', 'YYYY-MM-DD') AND START_DATE <= TO_DATE('2022-11-30', 'YYYY-MM-DD')
)
AND
FLOOR(A.DAILY_FEE * (1 - (B.DISCOUNT_RATE * 0.01)) * 30) >= 500000 AND
    FLOOR(A.DAILY_FEE * (1 - (B.DISCOUNT_RATE * 0.01)) * 30) < 2000000
ORDER BY 
    FLOOR(A.DAILY_FEE * (1 - (B.DISCOUNT_RATE * 0.01)) * 30) DESC, A.CAR_TYPE ASC, A.CAR_ID DESC