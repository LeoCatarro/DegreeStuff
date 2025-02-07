// Constructor
EarthApp = function() {
	Sim.App.call(this);
}

// Subclass Sim.App
EarthApp.prototype = new Sim.App();

// Our custom initializer
EarthApp.prototype.init = function(param) {
	// Call superclass init code to set up scene, renderer, default camera
	Sim.App.prototype.init.call(this, param);
	
    // Create the Earth and add it to our sim
    var earth = new Earth();
    earth.init();
    this.addObject(earth);
}

// Custom Earth class
Earth = function() {
	Sim.Object.call(this);
}

Earth.prototype = new Sim.Object();

Earth.prototype.init = function() {
    // Create our Earth with nice texture
    var earthmap = "../media/earth_surface.jpg";
    var geometry = new THREE.SphereGeometry(1, 32, 32);
    var texture = THREE.ImageUtils.loadTexture(earthmap);
    var material = new THREE.MeshBasicMaterial( { map: texture } );
    var mesh = new THREE.Mesh( geometry, material ); 

    // Let's work in the tilt
    mesh.rotation.x = Earth.TILT;
    
    // Tell the framework about our object
    this.setObject3D(mesh);    
}

Earth.prototype.update = function() {
	// "I feel the Earth move..."
	this.object3D.rotation.y += Earth.ROTATION_Y;
}

Earth.ROTATION_Y = 0.0025;
Earth.TILT = 0.41;
