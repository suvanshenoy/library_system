# Library System


### Cli tools required:

- cmake,
- typescript
- bun or pnpm or npm
- python
- gcc/clang
- poetry

### running the backend:

- use the following commands:
### first go into backend directory using cd

    cd backend

### use npm or bun or pnpm to run the commands below:
    - to build the project use:

      ``` 
      [your_package_manager] run bcpp or [your_package_manager] run build-cpp
      ```
    - after building the project an executable get created , run it using:

      ```
      ./LibraryBackend
      ```
    - to clean the directory having unwanted cmake builds and folders:

      ```
     [your_package_manager] run clean or [your_package_manager] run cl
      ```


### running the frontend:
     - to install the dependencies in package.json required for frontend run:

       ```
        [you_package_manager] install or [you_package_manager] i
       ```
     - to run the project:

       ```
       [your_package_manager] start
       ```
### running the python machine learning backend:
     - make sure you have poetry installed
     - to install the dependencies use:

       ```
        poetry install
       ```
     - next you need to go into the virtual environment created by poetry , for that your can use:

       ```
        poetry shell
       ```
     - to run the project:

       ```
        python3 -m flask --app main.py --debug run
       ```




Note: make sure you run them simultaneous in 3 sessions

