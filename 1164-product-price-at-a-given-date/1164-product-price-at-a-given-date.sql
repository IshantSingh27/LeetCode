# Write your MySQL query statement below
select p.product_id, ifnull(t.new_price , 10) as price
from (
    select distinct product_id
    from Products
) as p
left join (
    select product_id , new_price
    from Products
    where (product_id, change_date) in (
        select product_id, max(change_date)
        from Products
        where change_date <= date('2019-08-16')
        group by product_id
    )
) as t
on p.product_id = t.product_id;