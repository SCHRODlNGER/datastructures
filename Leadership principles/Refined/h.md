[2:34 PM, 2/6/2026] Samanyu: Situation:
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




[2:34 PM, 2/6/2026] Samanyu: Situation: When we expanded our policy system to include tiered cancellation / reschedules fees (charging more for last-minute changes), I was responsible for the technical rollout. Based on our successful launches in the UAE and Singapore, I pushed for a rapid deployment in the India market. I assumed that because the backend logic was sound and the "tiered" model had worked elsewhere, the customer reaction would be manageable.

The Failure: I overlooked the cultural and behavioral differences in the India market, where cancellation frequency and customer pushback are significantly higher. I ignored a suggestion from the CX team to include a "grace period" or a self-serve appeal flow at launch. I prioritized "Bias for Action" over "Customer Obsession," believing we could handle any fallout manually.

The Impact: The result was a disaster for our support operations. Daily tickets for "unfair fees" spiked from 30 to 150. Our CSAT score dropped from 76% to 72%, and the First Response Time (FRT) doubled to 30 minutes, effectively "bombing out" the support queue and causing massive burnout among our agents.

Task: My task changed from "managing a rollout" to "emergency damage control." I had to take full ownership of the ticket spike and design a technical solution to automate the mess I had created.

Action: I immediately met with the CX lead to apologize and understand the specific "SOP" agents used to resolve these disputes.

Short-term Fix: I personally designed a "Hard Rule" self-serve flow using fraud scores to filter out bad actors and provide instant refunds for low-risk, first-time offenders.

Long-term Solution: To handle complex cases, I led the integration of an LLM (GPT-3.5) into our chatbot. I implemented "Shadow Testing" where the model's decisions were compared against human agents.

The Pivot: When initial accuracy was low, I realized the data was "noisy." I personally cleaned the prompt data and increased the precision threshold to 90% to ensure we only automated clear-cut cases, protecting the firm’s revenue while satisfying the customer.

Result: The CSAT recovered to 78%, and we actually improved the FRT to 5 minutes—better than it was before the failure. However, the most important outcome was the mechanism I implemented: any future pricing or policy change now requires a "CX Impact Assessment" and a mandatory "Self-Serve Fallback" plan before it can be approved for rollout.


[2:34 PM, 2/6/2026] Samanyu: Situation: At Urban Company, I was the owner of the Policy System microservice. I was mentoring a junior developer on a critical "Routines" fee-flow project. In our microfrontend (MFE) architecture, the backend constructs a View-JSON that the client renders. A strict architectural boundary exists: the UI builder must be synchronous and pure; it should never trigger asynchronous information fetching.

Problem: During code review, I found the developer had implemented async calls directly within the UI builder logic. This violated our "separation of concerns" and threatened system stability. My initial code review comments were technical and brief, which led to defensive pushback from the developer who argued for a siloed implementation for "Routines" vs "On-Demand" flows.

The "Self-Critical" Pivot: I realized that part of this friction was my responsibility—I hadn't required a High-Level Design (HLD) document before coding started. Without that shared blueprint, the junior was essentially "coding in the dark." To resolve the tension, I moved the discussion from a digital PR to a face-to-face meeting.

Action: In our meeting, I explained the Strategy Pattern approach, showing how we could decouple information fetching from UI generation. To ensure the junior didn't feel "overruled" by my seniority alone, I brought in our Team Lead to provide a neutral architectural perspective. We agreed  that an HLD would be mandatory moving forward to avoid such friction.

Result: The developer refactored the code to a pure-functional UI builder. This architectural "cleanliness" paid off immediately: when we launched the "Bundles" feature a month later, we reused the UI builder and only had to write a new fetcher. This reduced development time by 40% and allowed us to deliver the project ahead of schedule. Most importantly, I earned the developer's trust by providing a path for growth rather than just a "Correction," leading to a permanent shift in our team's HLD process.