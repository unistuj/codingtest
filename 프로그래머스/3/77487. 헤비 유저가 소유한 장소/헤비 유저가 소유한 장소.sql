-- 코드를 입력하세요
select b.id, b.name, b.host_id
from
(
select c.host_id
from places c
group by c.host_id
having count(c.host_id) >= 2
) a left join
places b
on a.host_id = b.host_id
order by b.id asc;