# SecurityAndSafetyInOnlineHeatingControl

We keep different project elements in the folders *data*, *models*  and *libraries*.<br />

The *data* folder contains the historical data for weather and electricity prices.<br />
The *models* folder contains the Uppaal Stratego models both for evaluation (EM.xml) and learning (LM.xml).<br />
The *libraries* folder contains C Libraries we created to perform the following actions:<br />
* facilitate the communication between the house model (EM.xml) and the Uppaal Stratego controller (LM.xml)
* import historical data into the models
* read strategy decisions
* export data from the models to external files<br /><br />


To open the models, one must install Uppaal Stratego, which can be downloaded for free for non-commercial academic applications. The tool can be downloaded from the [link](https://uppaal.org/downloads/).

