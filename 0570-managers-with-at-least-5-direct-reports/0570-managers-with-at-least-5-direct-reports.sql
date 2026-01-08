# Write your MySQL query statement below
select e.name
from Employee as e
where e.id in (
    select managerId
    from employee
    group by managerId
    having count(*) >= 5
)