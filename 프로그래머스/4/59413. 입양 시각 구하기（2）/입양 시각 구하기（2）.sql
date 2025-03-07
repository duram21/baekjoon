with recursive cte as (
    select 0 as num
    union all
    select num + 1 as num
    from cte
    where num < 23
)

select cte.num as HOUR, count(DATETIME) as COUNT 
from cte left join ANIMAL_OUTS as AO on cte.num = HOUR(AO.DATETIME)
group by cte.num