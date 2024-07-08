-- 코드를 작성해주세요

select distinct i.id, i.email, i.first_name, i.last_name
from developers i cross join (select code
                   from skillcodes
                   where category= 'Front End') c
where (conv(i.skill_code, 10, 2) - conv(c.code, 10, 2)) not like '%9%' and (conv(i.skill_code, 10, 2) - conv(c.code, 10, 2)) >= 0
order by id