STAR Story: Revamping the Bookings List
Leadership Principles: Customer Obsession · Invent and Simplify · Dive Deep · Deliver Results

Situation
Urban Company’s original Bookings List API was slow and fragile. It fetched data across multiple microservices per booking, causing high latency (~800 ms P95 to 300ms p95), frequent UI breaks during service outages, and elevated error rates—especially under peak seasonal load. This undermined both user experience and engineering efficiency.

Task
I owned the redesign of the Bookings List API with the goal of improving performance, resilience, and maintainability while delivering a consistent and fast experience for end users.

Action
Analyzed service traces and downstream dependencies to identify performance bottlenecks and fault domains.

Proposed a modular three-layer architecture:

Core Data Layer: Aggregates booking IDs and statuses.

Decorator Layer: Enriches data with partner/customer info, pricing, etc.

Presentation Layer: Normalizes output using Urban Company’s Orion framework for consistent UI rendering.

Developed batch data fetches to reduce service call overhead and introduced stricter error handling to contain downstream failures.

Piloted a caching strategy at the decorator layer for completed bookings—where enriched data remains static—reducing redundant calls.

Instrumented real-time metrics and set up dashboards to monitor P95 latency, error rates, and service uptime under load and alerting thresholds.

Result
Reduced P95 latency from 800 ms to 400 ms even without caching.

Caching further reduced latency from 400ms to 320ms.

Dropped error rates from 10% to 1% during peak seasonal load thanks to robust fault containment.

Boosted user satisfaction: booking-page complaints fell dramatically and internal benchmarks flagged the system as “stable under peak pressure.”

Simplified development and debugging: engineers reported faster onboarding and increased confidence in the modular architecture.



1. There was no major change in the volume of requests for bookings list page. We had revamped the page for better UX and improved functionality including filtering and showing active bookings before completed bookings. 2. During our peak seasons on diwali and summer, We used to get an alert of increased error rate for the booking page API every 2 hrs and we had to manually scale up the dependency services. After our changes we had to reduced the error rate by incorporating error handling for downstream services to accomodate and serve base information with decorators 3. We had a TTL based cache system as the client usage patterns indicated that most users only view recently booked requests or requests in warranty, Both of these were handled by time based sorting and providing a filter on in warranty requests. 4. We had a canary based deployement through out the company and also had a AB testing facility available where initially rolled out the new bookings to internal users and friends and family to gather suggestions and improvements. And slowly rolled out region wise (city in our case).


Gaps & Risks
Tail-Latency Visibility

P95/P99 latencies remain unknown—critical for peak-load user experience.

Cache Staleness & Invalidation

Details on TTL choices, hit rates, and stale-data safeguards are missing.

Operational Cost

Impact on compute and memory resources from batching/caching not quantified.

Error-Serving vs. Error-Failing

Volume of “graceful degradation” serves versus outright failures needs clarity to assess user impact.

Release Discipline

Specifics on rollback triggers, canary size, and duration would strengthen confidence in the rollout strategy.




---------

State orchestrator

BPR should be tied to delivery
State derivation is very heavy - Calls multiple services (pricing) - 600 ms

- Make it independent - from delivery system




So when I was working in company, we had observed that bookings list on the app that we had we were using was very old, and it didn't deliver great customer experience. Where, like, a customer's request was scattered throughout. So we have started expanding our company. Into multiple domains where we were having sub serving single request we were bundling multiple requests together and serving them on different points of time. This caused, the booking slap to not be sufficient as earlier, the bookings have displayed each request individually, and sorted them based on the created app. So when the order was created, so this degraded the customer experience as he could not see the requests that were belonging to a particular project. Deliver at the same place. And also, the Bookings list had had problems with its facility. So it was dependent on multiple downstream services and it didn't have any state based ordering. And whenever one of them downstream services was getting broken or it was getting timed out. The whole it meant that the whole booking slash not visible to the user. This caused multiple issues as customers were not able to access the bookings during peak load and had been escalated multiple times in our peak seasons like summer and Diwali. So we had taken another project to tackle this customer issue. Where we wanted to provide a user with a great user experience. So they are going to see all the information that is required by that user at a single point without opening the request unless it is required. So customer is able to see the OTPs for the request quotations for that request, and also any help tickets that were opened on that particular request, to the to solve this issue, we had to go back to the roots. See why the existing system was not failing. Was not getting scaled up. So by deep diving into the existing architecture, we found that the architecture didn't have any proper structure. So it meant that the code was scattered multiple and it had caused multiple dependencies and downstream services. And we thought proper error handling. It meant that if one of the downstream service went down, we would not be displaying a list for all the request. So to mitigate this issue, we had broken the bookings list into three parts. The first one is getting the basic orders that we wanted to display them. It meant that we wanted to all the request based on two different activities, active request and completed request. If I and we had divided the bookings list into multiple parts, So the first part is an active request section. Where all the active requests that are part of the customer And in which, the customer is expecting some action to be taken to display at the top and all the completed requests be displayed at the bottom. So we had divided the structure into tail different parts. The first part is getting the booking request. Second part is, they're creating the booking request with multiple information. And the third part is presenting them to the user directly. So we had an framework for the front end called Orion. It meant that that back one drives the framework, we would be giving all the display terms that need to be displayed as adjacent to the front end. And the front end framework is going to display those buttons stuff. So by dividing our architecture into three different parts, we had solved the primary issue of error handling. So most of the error handlings that we were getting were due to helpful information, not the necessary information. So in case, the helpful information is not present, we should not not display the bookings. Instead, we should give the a minimal information for the request and display it. To mitigate this issue, we had used a combination of strategy and decorative pattern. So I'll come back to that in a bit. So while fetching the request, we had to fetch the request for that particular page. So that meant we had to query our order service all the request that were created for this user sorted by the created times and the list of information and the list of limit values of the request that we wanted to display. it is a responsibility of the booking gathering module So it's going to gather all the requests that need to be displayed. And it's going to get all the necessary information for that request, which is mandatory display. Like, what is the status of the request? What is the name of the request? Any thumbnail for that request, etcetera? And these requests are then slowed down to a decorator module the task of the decorator module is to should dictate the information with the necessary information. So this meant that we had decoupled the order gathering. With decorators. And we could have a specific error handling for each of the decorator. And mentioning what should the decorator do in case it fails. And this reduce some downstream services. Calls as the decorators have been implemented in a strategy pattern. If a request belongs to a particular category and is having this particular state, only a limited set of the on same services that it requires information from will be called of all the downstream services. This will reduce the number of request calls made from the market based service to downstream services. Which meant we had lower dependency on them. This has improved the customer experience by a lot. Where we have received multiple postures postures responses. When we had soft launched this into a cohort of users. This was also placed with the leadership that done an excellent job. And coming to the text technical methods that we have achieved, earlier, the booking time used to be somewhere around eight hundred to nine hundred milliseconds. Which means each of the page of the bookings will take at least eight hundred to nine nine hundred milliseconds for our power users, which are in the p ninety five We have brought down the p ninety five from eight hundred milliseconds to three three fifty milliseconds. Was a major improvement and made the bookings list near instantaneous This also allowed our team to further improve the booking service by adding more filters when the feature will only impact that booking gathering module and the decorator and presentation will not be affected as these both are independent.




---------- Final Version

Situation:
As we were expanding business into recurring requests , Existing bookings list API did not meet the requirements for new type of requests according the UX standard expectations. This needed a UI revamp to ensure that we could provide the best UX.
Also existing bookings list became cluttered as No single team had an ownership and since it was a cross cutting API. 
All the teams collectively made changes to satisfy their requirements. 
This made the bookings list API complex with no proper error handling which resulted in high error counts and entire requests failing.
UC did not have a single request state management system, 
We had an order management system and delivery management system (newly introduced by delivery team). 
Existing booking list API did not use these state management systems to deduce the state rather it depended on downstream services like pricing, order-management, delivery, matchmaking to deduce the state of the request.
We had very high latency for the bookings list API - ~800ms for a single page of request.
This also became a single point of failure as it is the only way a customer can access previously completed orders

Time line: May 2024 to June 2024

Task
To revamp the UI of the bookings list to improve UX
To bring down the latency of the API to load user requests lightning fast
To avoid single point of failure by having the API fault tolerant and provide minimal functionality incase of outages

Action

We deepdove into the bookings list to understand and identify the existing functionality such as 
state deducing system, How request information is being priorotised and fetched. 
In the deepdive sessions we found that the bookings list API is tightly coupled to multiple downstream services like order, pricing, matchmaking and delivery which became single Point of failure. 

To solve this we divided the API into 3 modules 
    - Request state management
    - Aggregation Module
    - Decorator Module
    - Presentation Module

By dividing the system into 4 modules, We were able to containarise the errors to each module. 
Since the aggregation Module is the core of fetching the requests and populating the requests with minimal data required it could not handle any errors. 
Decorator module is responsible to add aditional information to requests depending on its state, type and decorator priority.

Presentation module is a dumb module which utilises the information for above two modules and presents it to the user.

For the aggregation module, We first had the fetch the requests and deduce its state.
To manage state, I initially proposed that we could extend the delivery state management system (called studio) to also handle requests before provider assignment.
We pitched this idea to the leaders and were met with resistance that it would be a risky change, which might have an affect on the upcoming peak season of summer.
After understanding the concerns, I went back to the drawing board. I had pitched an idea that we might be able to utilise both the order management system's state manager and studio and let the bookings API deduce its own state. 
This while still depended on two different services to function correctly, mitigated the risky change of modifying existing complex state managers while having nearly same latency. This is how the system deduced the state of the system.

Decorator module is what I have designed and wanted it to be fault tolerant down to decorator level. This meant that even if one decorator has failed due to circuit breaker issues or downstream services not working, 
It should contain the error and determine how the request should be. This meant each decorator has two main function, Initial is the main flow and the secondary is the how the decorator should behave incase of errors.
This made the system lighter by ensuring that each requests only decorates the information it needs without calling un-necessary downstream services.

Result:

By implementing both of these Ideas, 
We were able to deliver a modular bookings list API that is fault tolerant and can work minimally incase of outages.
P95 latency dropped down to ~400ms
Received shoutout from the leadership as our team has solved a critical pain point. 
Reduced error rates (dropped ~10% daily).
Controlled sucessful rollout by using AB testing (internally then slowly increasing load).
Decorator utilised by other teams to serve their needs (like helpcenter which decorator ticket information directly on the bookings API).
Multiple dashboards and alerting for each decorator, Which would be helpful in identfying decorator level metrics.

