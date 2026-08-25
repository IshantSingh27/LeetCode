# Write your MySQL query statement below
select round(sum(case when d.order_date = d.customer_pref_delivery_date then 1 else 0 end) * 100 /
count(*)  , 2) as immediate_percentage 
from Delivery as d
where (order_date, customer_id) in (
    select min(order_date) as order_date, customer_id
    from Delivery
    group by customer_id
)