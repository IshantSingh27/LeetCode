# Write your MySQL query statement below
select round(count(distinct a.player_id)  / 
(select count(distinct player_id) from Activity), 2) as fraction
from Activity as a
join (
    select player_id, min(event_date) as first_login
    from Activity 
    group by player_id
) as f
on a.player_id = f.player_id
where a.event_date = date_add(f.first_login , interval 1 day);