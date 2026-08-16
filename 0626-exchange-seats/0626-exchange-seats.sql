# Write your MySQL query statement below
select s1.id, case when s1.id % 2 = 1 and 
s2.id is null then s1.student 
else s2.student end as student
from Seat as s1 
left join Seat as s2 
on s2.id = case when s1.id % 2 = 1 then s1.id + 1
else s1.id - 1 end
order by s1.id