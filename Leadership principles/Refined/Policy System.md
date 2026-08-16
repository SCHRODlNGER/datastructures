STAR Story: Quality and Ownership of the Policy System
Leadership Principles: Ownership · Insist on the Highest Standards · Dive Deep

Situation
The policy engine—responsible for enforcing cancellation, rescheduling, and partner policies—had no formal quality gates. Code and design reviews were ad hoc, unit-test coverage was inconsistent, and production bugs in policy enforcement were causing customer and partner frustration.

Task
As the de facto owner of the policy system, I needed to establish rigorous review and testing processes to ensure every policy change met high quality standards and would behave predictably in production.

Action
Partnered with product managers and business stakeholders to deeply understand each policy’s requirements and edge cases.

Introduced mandatory design-review meetings before any major feature work, documenting system interactions and failure modes.

Enforced a pull-request policy requiring at least two independent reviewers and adherence to SOLID principles for every code change.

Established a unit-test standard of 100% line, branch, and condition coverage, integrating coverage checks into our CI pipeline to block merges if tests fell short.

Mentored a new SDE-1, pairing on test-case design and code-review best practices to bring them up to speed quickly.

Result
Caught 99% of defects in unit tests, preventing production policy failures and eliminating rollback incidents.

Accelerated safe deployments: confidence in test coverage reduced hotfixes by over 80%.

Earned direct praise from senior leadership for taking full ownership of the project and delivering a robust, scalable policy engine.


Superficial Coverage Risk

100% line/branch/condition coverage can incentivize superficial tests that don’t validate actual behavior. Details on how test quality was measured are missing.

CI Overhead

Enforcing full coverage often lengthens build times and can frustrate engineers; the story lacks data on pipeline performance impact.

Velocity Trade-Offs

No discussion of how urgent fixes or small features were handled when coverage or review gates threatened to delay production changes.

Maintenance Burden

As policies evolve, maintaining 100% coverage can become onerous. There’s no mention of strategies (e.g., test templates, code generators) to reduce this burden.


1. Situation & Task
You led the “fee pass” program at Urban Company from September 2023–January 2024 in a 3-person team (you, a Tech Lead, one developer).

Post-Diwali ’23, P95 latency in Bookings List API and policy enforcement UI spiked, driving down CSAT.

Business goal: roll out Summer ’24 “fee pass” to support regular bookings, routines, and bundles, while enabling new revenue streams.

Deliverables:

Operations dashboard for customizable fee policies

Customer-facing UI across three service types

Help-center chatbot for self-serve policy guidance

2. Actions
Stakeholder Alignment & Discovery • Ran deep-dive workshops to capture every cancellation edge case and consolidated similar requirements.

Phased, Iterative Delivery

Core fee logic + cancellation flows

Partner-led & bundle scenarios

UI refinements + chatbot integration

Transparent Feedback Loops • Weekly staging demos for leadership and operations to gather early feedback and course-correct.

Mentorship & Issue Resolution • Coached the junior developer through a complex UI-timer bug, delivering a temporary patch while coordinating a permanent fix with the Orion team.

3. Results
CSAT uplift from 75% → 78% (+3%) in A/B test cohorts

Enabled routines and bundles sales, driving 50% revenue growth in Singapore—system was the cornerstone for customizable fee plans

Delivered full system within the planned four-month timeline

Operations team adopted the policy dashboard for real-time tweaks

Help-center chatbot qualitatively reduced policy-related support tickets

4. Leadership Principles Alignment

Principle	Evidence
Customer Obsession	Improved cancellation clarity and self-serve support, boosting CSAT
Think Big	Architected for new routines/bundles revenue stream, not just fee refunds
Ownership	Solely drove design, development, rollout, and cross-team coordination
Dive Deep	Documented all edge cases; consolidated complex cancellation requirements
Invent & Simplify	Phased approach broke down high complexity into manageable releases
Earn Trust	Maintained transparency via weekly demos; mentored and supported the team
Deliver Results	Achieved measurable CSAT gain, significant revenue impact, and on-time delivery



------------ Final

Situation:

Business wanted to introduce a tiered cancellation & reschedule policy to be enforced for each request. 
We had to build a modular service which could be used a general policy system to enforce all policies across UC. 
We are a team of 3 people (1. SDE - 3, Me and new SDE-1) and the timeline for this system to be delivered from Nov 2023 to Feb 2024. 
We have divided up the work by him taking lead on the core policy engine and I have taken responsibility on the external service dependencies, policy calculation and UI display system. 

Task:
To build the customer experience flow for displaying and enforcing the new policy to customer across request journey.

Action:
Collaborated with stakeholders to understand their requirements, filled in the gap for edge cases like auto reschedule, Partner not assigned, Partner no show, fraud customer. 

Drafted initial design documents for each of the module while ensuring that each module can be extended to accomodate different template based policies that can be created and proactively seeked feedback from my tech lead before implementing.

Collaborated with multiple external teams like pricing, helpcenter, order system to get the information needed for policy evaluation.

Teamed up with SDE-1 to help draft designs for smaller modules while providing feedback and thoughtprocess on their desgin. This opened up junior to approach me more freely to improve himself.

Prepared a release plan documenting how we will be releasing and ensuring proper metrics, logs and error handling is present along with how to fallback incase of issues.

We have released the new policy system usign AB testing with slow rollout behind feature flags to ensure we have control over deployment.

Result:
We release the policy system with no major bugs in the core flow. 
I got praised by my manager for guiding the junior and helping him improve. This encouraged my manager to schedule team building sessions.
Policy system improved Service delivery by 2% due to lesser cancellation by customers.
I was given additional features with to further enhance policy system like partner payouts, free passes as a result of increased confidence by my tech lead.
